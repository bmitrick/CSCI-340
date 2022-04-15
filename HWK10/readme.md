# CSCI-340 Homework 10: Blake Mitrick
---

## 1. Is it fundamentally necessary to store on disk the information about the unallocated disk sectors? Explain why.

It is not fundamentally necessary, however, it is a good idea. In order to avoid needing to track all the unallocated disk information it is possible for the OS to simply track the information about all the allocated data and assume that all the spots on the disk that are not allocated are unallocated. This would essentially be saying that everything that is not expressly marked as allocated is unallocated. This could lead to issued down the road but it is possible to run an OS without a list of unallocated disk sectors.

## 2. In some early release of an operating system, when a file was deleted, its sectors reverted to the free list but they were not erased. What problems do you think may result from this? Why do you think the blocks were not erased?

A few problems could arise from not actually deleting deleted information. Firstly, this could be a security issue as bad actors searching through "empty" disk space could result in the retrieval of sensitive information that was thought to have been deleted. It could also lead to to some issues when storing information since an undetected error in saving a new file to the sector of a disk where the old information was stored could lead the previously "free" information to corrupt the newly saved file. These blocks were probably not erased as it was seen as a waste of time and resources to remove the data, if it needed to be overwritten in the future, it would be, just mark it as unused and when its needed it will be overwritten.

## 3. You are designing a file system from scratch. The disk driver allows you complete control over the placement of data on the disk. Assuming that you have settled for a File Allocation Table (FAT) architecture, where would be the best place to store the table on disk?



## 4. Contiguous allocation of files leads to disk fragmentation. Explain why?

## 5. Can we implement symbolic links in DOS (FAT file system)? If so, show how, and if not, explain why.
