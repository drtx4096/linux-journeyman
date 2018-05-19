/*
 *  ioctl.c - the process to use ioctl's to control the kernel module
 *
 *  Until now we could have used cat for input and output.  But now
 *  we need to do ioctl's, which require writing our own process.
 */

/* 
 * device specifics, such as ioctl numbers and the
 * major device file. 
 */
#include "chardev.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>	 /* open */
#include <unistd.h>	/* exit */
#include <sys/ioctl.h> /* ioctl */

const size_t BUFFER_LEN = 100;

/* 
 * Functions for the ioctl calls 
 */

void ioctl_set_msg(int file_desc, char *message)
{
	int ret_val;
	char empty[1] = {0};

	// A null input message is to clear the device buffer.
	if (message)
	{
		ret_val = ioctl(file_desc, IOCTL_SET_MSG, message);
	}
	else
	{
		ret_val = ioctl(file_desc, IOCTL_SET_MSG, empty);
	}

	if (ret_val < 0)
	{
		printf("ioctl_set_msg failed:%d\n", ret_val);
		exit(-1);
	}
}

void ioctl_get_msg(int file_desc, SizedBuffer* buffer)
{
	int ret_val;

	/* 
	 * Warning - this is dangerous because we don't tell
	 * the kernel how far it's allowed to write, so it
	 * might overflow the buffer. In a real production
	 * program, we would have used two ioctls - one to tell
	 * the kernel the buffer length and another to give
	 * it the buffer to fill
	 */
	ret_val = ioctl(file_desc, IOCTL_GET_MSG, buffer);

	if (ret_val < 0)
	{
		printf("ioctl_get_msg failed:%d\n", ret_val);
		exit(-1);
	}

	if(buffer->buffer[buffer->length - 1]){
		// Truncate
		printf("Truncating returned data!\n");
		buffer->buffer[buffer->length - 1] = '\0';
	}
	printf("get_msg message: '%s'\n", buffer->buffer);
}

/*
Read the contents of the device buffer a byte at a time until a null 
is reached.
*/
void ioctl_get_nth_byte(int file_desc)
{
	int i;
	char c;

	printf("get_nth_byte message: ");

	i = 0;
	do
	{
		c = ioctl(file_desc, IOCTL_GET_NTH_BYTE, i++);

		if (c < 0)
		{
			printf("ioctl_get_nth_byte failed at the %d'th byte:\n",
				   i);
			exit(-1);
		}
		putchar(c);
	} while (c);
	putchar('\n');
}

/* 
 * Main - Call the ioctl functions 
 */
int main()
{
	int file_desc, ret_val;
	char *msg = "Message passed by ioctl";
	char received[100] = {0};
	SizedBuffer read_buffer;

	read_buffer.buffer = (char*)malloc(BUFFER_LEN);
	if(!read_buffer.buffer)
	{
		printf("Failed to allocate read_buffer!\n");
		exit(-1);
	}
	read_buffer.length = BUFFER_LEN;

	file_desc = open(DEVICE_FILE_NAME, 0);
	if (file_desc < 0)
	{
		printf("Can't open device file: %s\n", DEVICE_FILE_NAME);
		exit(-1);
	}

	// Display current contents of device buffer
	ioctl_get_nth_byte(file_desc);

	// Get the contents of the device buffer using a sized buffer.
	ioctl_get_msg(file_desc, &read_buffer);


	// If the device buffer is empty, set its contents
	// else clear it.
	if (!strlen(read_buffer.buffer))
	{
		// Set the device buffer to some value
		ioctl_set_msg(file_desc, msg);
	}
	else
	{
		// Clear the device buffer
		ioctl_set_msg(file_desc, NULL);
	}
	close(file_desc);
	return 0;
}
