# CSCI-340 Homework 8: Blake Mitrick
---

## 1. Device information
### a) Program lsblk
```
blake@CSCI-340:~$ lsblk
NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
loop0    7:0    0 110.7M  1 loop /snap/core/12821
loop1    7:1    0   704K  1 loop /snap/gnome-characters/741
loop2    7:2    0   2.5M  1 loop /snap/gnome-system-monitor/174
loop3    7:3    0 149.9M  1 loop /snap/gnome-3-28-1804/67
loop4    7:4    0   548K  1 loop /snap/gnome-logs/106
loop5    7:5    0  65.2M  1 loop /snap/gtk-common-themes/1519
loop6    7:6    0   2.5M  1 loop /snap/gnome-calculator/884
loop7    7:7    0  1008K  1 loop /snap/gnome-logs/61
loop8    7:8    0     4K  1 loop /snap/bare/5
loop9    7:9    0  61.9M  1 loop /snap/core20/1376
loop10   7:10   0 164.8M  1 loop /snap/gnome-3-28-1804/161
loop11   7:11   0  42.8M  1 loop /snap/gtk-common-themes/1313
loop12   7:12   0   3.7M  1 loop /snap/gnome-system-monitor/100
loop13   7:13   0 110.8M  1 loop /snap/core/12725
loop14   7:14   0   219M  1 loop /snap/gnome-3-34-1804/77
loop15   7:15   0 248.8M  1 loop /snap/gnome-3-38-2004/99
loop16   7:16   0  61.9M  1 loop /snap/core20/1361
loop17   7:17   0   2.6M  1 loop /snap/gnome-calculator/920
loop18   7:18   0  55.5M  1 loop /snap/core18/2284
loop19   7:19   0  55.5M  1 loop /snap/core18/2344
loop20   7:20   0  14.8M  1 loop /snap/gnome-characters/296
loop21   7:21   0 247.9M  1 loop /snap/gnome-3-38-2004/87
sda      8:0    0    10G  0 disk
└─sda1   8:1    0    10G  0 part /
sr0     11:0    1  1024M  0 rom  
```
#### According to the output when you input ```lsblk --help```, ```lsblk``` lists the information about block devices. This command also tells us about the columns of the output...
* NAME) The name of the device
* MAJ:MIN) The major:minor device number of the device
* RM) Indicates if the device is removable
* SIZE) The size of the device
* RO) Indicates if the device is read-only
* TYPE) What kind of device the device is
* MOUNTPOINT) Where the device is mounted in the system

### b) Program lsusb
