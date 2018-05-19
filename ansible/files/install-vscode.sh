#!/bin/sh

# Install Visual Studio Code and extensions on Fedora

sudo rpm --import https://packages.microsoft.com/keys/microsoft.asc
sudo sh -c 'echo -e "[code]\nname=Visual Studio Code\nbaseurl=https://packages.microsoft.com/yumrepos/vscode\nenabled=1\ngpgcheck=1\ngpgkey=https://packages.microsoft.com/keys/microsoft.asc" > /etc/yum.repos.d/vscode.repo'
dnf check-update
sudo dnf install code
code --install-extension ms-python.python
code --install-extension ms-vscode.cpptools
code --install-extension 13xforever.language-x86-64-assembly
