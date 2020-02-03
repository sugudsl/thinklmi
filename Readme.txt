Building and installation procedure
Think-LMI kernel Module

Build Procedure:
sudo su
cd thinkpad-wmi-master
make
insmod drivers/platform/x86/think-lmi.ko


thinklmi Application program

cd thinklmi
gcc -o thinklmi thinklmi.c

./thinklmi getsettings 

The above command will display the BIOS settings

./thinklmi -g WakeOnLANDock
The above command will get the available setings for WakeOnLANDock

./thinklmi -s WakeOnLANDock Enable
The above command will set the new value to the BIOS Setting
