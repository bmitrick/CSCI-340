# CSCI-340 Homework 10: Blake Mitrick
---

## 1. Is it fundamentally necessary to store on disk the information about the unallocated disk sectors? Explain why?

It is not fundamentally necessary, however, it is a good idea. In order to avoid needing to track all the unallocated disk information it is possible for the OS to simply track the information about all the allocated data and assume that all the spots on the disk that are not allocated are unallocated. This would essentially be saying that everything that is not expressly marked as allocated is unallocated. This could lead to issued down the road but it is possible to run an OS without a list of unallocated disk sectors.

## 2. In some early release of an operating system, when a file was deleted, its sectors reverted to the free list but they were not erased. What problems do you think may result from this? Why do you think the blocks were not erased?

A few problems could arise from not actually deleting deleted information. Firstly, this could be a security issue as bad actors searching through "empty" disk space could result in the retrieval of sensitive information that was thought to have been deleted. It could also lead to to some issues when storing information since an undetected error in saving a new file to the sector of a disk where the old information was stored could lead the previously "free" information to corrupt the newly saved file. These blocks were probably not erased as it was seen as a waste of time and resources to remove the data, if it needed to be overwritten in the future, it would be, just mark it as unused and when its needed it will be overwritten.

## 3. You are designing a file system from scratch. The disk driver allows you complete control over the placement of data on the disk. Assuming that you have settled for a File Allocation Table (FAT) architecture, where would be the best place to store the table on disk?

I would place this data in the middle stripe between the edge and the center of the platter. I would put it here since it would be in the center point for data storage. This would make it optimal for the storage of data on the spinning disk since the drive could start with the reading head on the FAT, find the location of the data it needs, and it would be able to reference it and come back to the FAT while covering as little distance as possible (at least on average). If it were to be on the very center or edge of the plate it has the possiblilty that the head would need to move the full radius of the plate in order to get to the information it needs while when the FAT is stored on the middle stripe it would at most need to cover half the radius of the disk.

## 4. Contiguous allocation of files leads to disk fragmentation. Explain why?

When contiguously allocating files, all the blocks the file is subdevided into will be found consecutively in the storage of the computer. This means that when the file is deleted, there will be a new free space the size of the file where the file once was on the storage device. This is similar to memory managenemt where, eventually, as files are added and deleted, small chunks of memory develop as new programs don't quite fill up all the space of the program that was once in that chunk of memory. Eventually, the only free spaces will be tiny chunks which are too small for files to fit into, leading the file to need to be broken up and fragmented in order to be stored on the storage device.

## 5. Can we implement symbolic links in DOS (FAT file system)? If so, show how, and if not, explain why.

We can implement symbolic links in DOS. 
