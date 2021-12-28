# third_party_fsck_msdos

#### 介绍
fsck_msdos是Fat32文件系统fsck工具，是DOS/Windows 用来检查和维护不一致的(FAT) 文件系统。若系统掉电或磁盘发生问题，可利用fsck命令对文件系统进行检查。  

命令格式：

    fsck_msdosfs -p [-Cf] filesystem ...
    fsck_msdosfs [-CMny] filesystem ...

第一种形式整理指定的文件系统。 当检测到 FAT 文件系统时，它通常由在自动重启期间从 /etc/rc 运行的 fsck(8) 启动。 整理文件系统时，fsck_msdosfs 将以非交互方式修复常见的不一致。 如果发现更严重的问题，fsck_msdosfs 不会尝试修复它们，表明它没有成功，然后退出。  

第二种形式检查指定的文件系统并尝试修复所有检测到的不一致，在进行任何更改之前请求确认。
  
可选参数：  
- -C ：与相应的 fsck(8) 选项的兼容性（如果干净则跳过检查），定义为无操作。
- -F ：与包装器 fsck(8) 的兼容性，它试图确定文件系统是否需要在前台立即清理，或者是否可以推迟到后台清理。必须始终在前台清理 FAT (MS-DOS) 文件系统。始终为此选项返回非零退出代码。
- -M ：导致在检查 FAT32 文件系统时不使用 mmap(2)。此选项主要用于调试目的，通常不需要。当实用程序无法执行 mmap(2) 或指定 -M 时，它会自动回退到使用 4 MiB 的简单 LRU 缓存。
- -f ：强制 fsck_msdosfs 在整理时检查“干净”的文件系统。
- -n ：假定“否”作为所有操作员问题的答案，“继续？”除外。
- -p ：整理指定的文件系统。
- -y ：假定“是”作为所有操作员问题的答案。  

  
#### 来源
fsck_msdos是freebsd/freebsd-src/tree/master/sbin下的一个功能，源代码路径：

    https://github.com/freebsd/freebsd-src/tree/master/sbin/fsck_msdosfs  

BSD使用手册链接：

    https://www.freebsd.org/cgi/man.cgi?query=fsck_msdosfs&sektion=8

#### 如何获取  
  
    https://github.com/freebsd/freebsd-src.git  



