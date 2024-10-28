struct buf
{
  int valid;             // has data been read from disk?
  int disk;              // does disk "own" buf?
  uint dev;              // 设备编号
  uint blockno;          // 磁盘块号
  struct sleeplock lock; // 睡眠锁
  uint refcnt;           // 引用计数
  struct buf *prev;      // LRU cache list，指向链表上一个缓冲区
  struct buf *next;      // 指向链表下一个缓冲区
  uchar data[BSIZE];     // 实际存储缓冲区数据的数组
  uint timestamp;        // 时间戳，用于记录缓冲区最后访问时间或修改时间
};
