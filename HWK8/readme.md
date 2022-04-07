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
#### The columns of the output...
* NAME) The name of the device
* MAJ:MIN) The major:minor device number of the device
* RM) Indicates if the device is removable
* SIZE) The size of the device
* RO) Indicates if the device is read-only
* TYPE) What kind of device the device is
* MOUNTPOINT) Where the device is mounted in the system

### b) Program lsusb
```
blake@CSCI-340:~$ lsusb
Bus 001 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
```
#### The columns of the output...
* Bus) The bus on which the device is located
* Device) The device number given to the device by the OS
* ID) The vendor's id followed by the product id then followed by the developer of the device as well as what the device is

## 2) Storage Nomenclature
### a) Host Bus Adapter (HBA)
* The HBA is a device that allows for additional resources. Generally this means networking capabilities or storage. These adapters can vary from devices like SATA, Fiber Channel, and iSCSI devices. Other examples of these adapters can include USB or Ethernet. HBAs are either integrated in the motherboard of the computer or connected as an expansion card.

### b) Serial ATA (SATA)
* SATA is a type of bus interface. Generally, SATA is used to connect mass storage such as hard drives or solid-state drives. Replacing Parallel ATA (PATA), SATA was released in the year 2000 and is managed by the Serial ATA International Organization (SATA-IO).

### c) Fiber Channel
* Fiber Channel is a protocol for in-order, lossless delivery of data. Generally, Fiber Channel is used to transmit data to and from data storage servers. Fiver Channel runs on fiber optic cables or, less commonly, copper cabling. FC supports data rates from 1-128 gigabit per second, vastly outperforming most other protocols.

### d) iSCSI
* iSCSI stands for Internet Small Computer Systems Interface. iSCSI is mainly used to transmit data between computers and storage devices on a local network. iSCSI can be used on local area networks (LAN), wide area networks (WAN), or the internet.

### e) Storage Area Network (SAN)
* A SAN is a network which allows for block-level data storage. These networks are used to access storage devices such as hard drive arrays. Generally, a SAN is its own dedicated network of storage devices and is not accessible from the LAN.

### f) Network Attached Storage (NAS)
* A NAS is a storage server connected to a local network. This allows computers attached to the network to access and manipulate the data stored on the NAS. Network attached storage devices often run some form of RAID in order to ensure data safety through redundancy. Network attached storage devices can consist of hard drives, solid-state drives, or other forms of long term storage.
