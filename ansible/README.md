The Ansible scripts here are used to configure a system that mirrors the evaluation system in the Linux Journeyman evaluation. The scripts can also apply some customizations to the system for the purpose of supporting practice for the evaluation.

# Provision Evaluation System

Use the following procedure to create a system which replicates the evaluation system.

1. Load Fedora Workstation 25 x86_64 (*Need to verify architecture*)
2. Install Ansible: `sudo dnf install -y ansible`
3. Apply eval playbook: `sudo ansible-playbook eval.yaml -e user=<user>`

To customize the system for developmental practice:

Apply the customize playbook:
```
sudo ansible-playbook customize.yaml -e user=<user>
```

