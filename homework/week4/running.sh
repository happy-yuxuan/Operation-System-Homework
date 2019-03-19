#!/bin/sh
# 测试对应 BufferSize的用户态和系统时间
time ./mycat 1 slide.pdf  /dev/null
time ./mycat 1024 slide.pdf  /dev/null
time ./mycat 4096 slide.pdf  /dev/null

