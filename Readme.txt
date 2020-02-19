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


./thinklmi -g [BIOS Setting]

eg: ./thinklmi -g WakeOnLANDock
The above command will get the available options for WakeOnLANDock

./thinklmi -s [BIOS Setting] [option]

eg: ./thinklmi -s WakeOnLANDock Enable
The above command will set the new value to the BIOS Setting

./thinklmi -p [Password] [encoding] [keyboard language]

eg: ./thinklmi -p hello ascii us
If the supervisor password is set as hello, with ascii encoding
and the keyboard type is US, the above command will authenticate the BIOS setting
Once authenticated, it remains valid till the next restart.


./thinklmi -c [Password] [Password] [Passwordtype] [encoding] [keyboard language]

eg: ./thinklmi -p hello newpd pap ascii us
Change the supervisor password or power on password using this command.
Do a reboot for the new password to take effect.



