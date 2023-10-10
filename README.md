

# libzmq

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug
make

make test
```

# zmq_test

```
gcc -g test.cxx -o test -L/home/ec2-user/code/libzmq/build/lib -I /home/ec2-user/code/libzmq/include/ -lzmq

export LD_LIBRARY_PATH=/home/ec2-user/code/libzmq/build/lib; ./test
```

# debug gdb
```
export LD_LIBRARY_PATH=/home/ec2-user/code/libzmq/build/lib; gdb ./test

b zmq::session_base_t::engine_error

```


```
# set to 40000 41000
sudo vim /etc/sysctl.conf   (add line net.ipv4.ip_local_port_range = 40000 41000)
sudo sysctl -p /etc/sysctl.conf .
sysctl net.ipv4.ip_local_port_range


sudo tcpdump -i any port 40500 -n

```


```
09:10:00.316158 lo    In  IP 127.0.0.1.40474 > 127.0.0.1.40500: Flags [S], seq 1056546511, win 65495, options [mss 65495,sackOK,TS val 59630315 ecr 0,nop,wscale 7], length 0
09:10:00.316163 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40474: Flags [R.], seq 0, ack 1056546512, win 0, length 0
09:10:00.500454 lo    In  IP 127.0.0.1.40490 > 127.0.0.1.40500: Flags [S], seq 2686512761, win 65495, options [mss 65495,sackOK,TS val 59630499 ecr 0,nop,wscale 7], length 0
09:10:00.500460 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40490: Flags [R.], seq 0, ack 122071596, win 0, length 0
09:10:00.645699 lo    In  IP 127.0.0.1.40494 > 127.0.0.1.40500: Flags [S], seq 1429384248, win 65495, options [mss 65495,sackOK,TS val 59630644 ecr 0,nop,wscale 7], length 0
09:10:00.645705 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40494: Flags [R.], seq 0, ack 1429384249, win 0, length 0


09:10:00.824997 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [S], seq 2572395396, win 65483, options [mss 65495,sackOK,TS val 59630824 ecr 59567859,nop,wscale 7], length 0
09:10:00.825003 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [S.], seq 2572395396, ack 2572395397, win 65483, options [mss 65495,sackOK,TS val 59630824 ecr 59630824,nop,wscale 7], length 0
09:10:00.825006 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 1, win 512, options [nop,nop,TS val 59630824 ecr 59630824], length 0
09:10:00.825104 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 1:11, ack 1, win 512, options [nop,nop,TS val 59630824 ecr 59630824], length 10
09:10:00.825107 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 11, win 512, options [nop,nop,TS val 59630824 ecr 59630824], length 0
09:10:00.825118 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 11:12, ack 11, win 512, options [nop,nop,TS val 59630824 ecr 59630824], length 1
09:10:00.825125 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 12:65, ack 12, win 512, options [nop,nop,TS val 59630824 ecr 59630824], length 53
09:10:00.825155 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 65:92, ack 65, win 512, options [nop,nop,TS val 59630824 ecr 59630824], length 27
09:10:00.825176 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [F.], seq 92, ack 92, win 512, options [nop,nop,TS val 59630824 ecr 59630824], length 0
09:10:00.825179 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 93, win 512, options [nop,nop,TS val 59630824 ecr 59630824], length 0

```


## ISSUE

### BAD
```
09:57:53.937767 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40466: Flags [R.], seq 0, ack 108455980, win 0, length 0
09:57:54.127068 lo    In  IP 127.0.0.1.40470 > 127.0.0.1.40500: Flags [S], seq 2565083455, win 65495, options [mss 65495,sackOK,TS val 62504126 ecr 0,nop,wscale 7], length 0
09:57:54.127071 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40470: Flags [R.], seq 0, ack 231392135, win 0, length 0
09:57:54.324383 lo    In  IP 127.0.0.1.40474 > 127.0.0.1.40500: Flags [S], seq 3013252083, win 65495, options [mss 65495,sackOK,TS val 62504323 ecr 0,nop,wscale 7], length 0
09:57:54.324388 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40474: Flags [R.], seq 0, ack 3013252084, win 0, length 0
09:57:54.476636 lo    In  IP 127.0.0.1.40490 > 127.0.0.1.40500: Flags [S], seq 347750353, win 65495, options [mss 65495,sackOK,TS val 62504475 ecr 0,nop,wscale 7], length 0
09:57:54.476640 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40490: Flags [R.], seq 0, ack 347750354, win 0, length 0
09:57:54.667949 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [S], seq 326616065, win 65483, options [mss 65495,sackOK,TS val 62504667 ecr 62481315,nop,wscale 7], length 0
09:57:54.667958 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [S.], seq 326616065, ack 326616066, win 65483, options [mss 65495,sackOK,TS val 62504667 ecr 62504667,nop,wscale 7], length 0
09:57:54.667961 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 1, win 512, options [nop,nop,TS val 62504667 ecr 62504667], length 0
09:57:54.668047 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 1:11, ack 1, win 512, options [nop,nop,TS val 62504667 ecr 62504667], length 10
09:57:54.668051 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 11, win 512, options [nop,nop,TS val 62504667 ecr 62504667], length 0
09:57:54.668060 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 11:12, ack 11, win 512, options [nop,nop,TS val 62504667 ecr 62504667], length 1
09:57:54.668068 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 12:65, ack 12, win 512, options [nop,nop,TS val 62504667 ecr 62504667], length 53
09:57:54.668087 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 65:92, ack 65, win 512, options [nop,nop,TS val 62504667 ecr 62504667], length 27
09:57:54.708963 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 92, win 512, options [nop,nop,TS val 62504708 ecr 62504667], length 0
```

### GOOD
```
10:13:57.698649 lo    In  IP 127.0.0.1.40468 > 127.0.0.1.40500: Flags [S], seq 2285633953, win 65495, options [mss 65495,sackOK,TS val 63467697 ecr 0,nop,wscale 7], length 0
10:13:57.698654 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40468: Flags [R.], seq 0, ack 2285633954, win 0, length 0
10:13:57.835886 lo    In  IP 127.0.0.1.40472 > 127.0.0.1.40500: Flags [S], seq 3740063029, win 65495, options [mss 65495,sackOK,TS val 63467835 ecr 0,nop,wscale 7], length 0
10:13:57.835892 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40472: Flags [R.], seq 0, ack 1078652377, win 0, length 0
10:13:57.966115 lo    In  IP 127.0.0.1.40482 > 127.0.0.1.40500: Flags [S], seq 1019657631, win 65495, options [mss 65495,sackOK,TS val 63467965 ecr 0,nop,wscale 7], length 0
10:13:57.966121 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40482: Flags [R.], seq 0, ack 1068807057, win 0, length 0
10:13:58.124384 lo    In  IP 127.0.0.1.40498 > 127.0.0.1.40500: Flags [S], seq 3452255652, win 65495, options [mss 65495,sackOK,TS val 63468123 ecr 0,nop,wscale 7], length 0
10:13:58.124389 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40498: Flags [R.], seq 0, ack 1069119880, win 0, length 0
10:13:58.260628 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [S], seq 3386550211, win 65495, options [mss 65495,sackOK,TS val 63468259 ecr 0,nop,wscale 7], length 0
10:13:58.260636 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [S.], seq 3386550211, ack 3386550212, win 65495, options [mss 65495,sackOK,TS val 63468259 ecr 63468259,nop,wscale 7], length 0
10:13:58.260639 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 1, win 512, options [nop,nop,TS val 63468259 ecr 63468259], length 0
10:13:58.260812 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 1:11, ack 1, win 512, options [nop,nop,TS val 63468259 ecr 63468259], length 10
10:13:58.260815 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 11, win 512, options [nop,nop,TS val 63468259 ecr 63468259], length 0
10:13:58.260827 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 11:12, ack 11, win 512, options [nop,nop,TS val 63468259 ecr 63468259], length 1
10:13:58.260835 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 12:65, ack 12, win 512, options [nop,nop,TS val 63468259 ecr 63468259], length 53
10:13:58.260885 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [P.], seq 65:92, ack 65, win 512, options [nop,nop,TS val 63468260 ecr 63468259], length 27
10:13:58.300970 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 92, win 512, options [nop,nop,TS val 63468300 ecr 63468260], length 0
10:14:28.291074 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [F.], seq 92, ack 92, win 512, options [nop,nop,TS val 63498290 ecr 63468300], length 0
10:14:28.291085 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40500: Flags [.], ack 93, win 512, options [nop,nop,TS val 63498290 ecr 63498290], length 0
10:14:28.406352 lo    In  IP 127.0.0.1.40558 > 127.0.0.1.40500: Flags [S], seq 1355520654, win 65495, options [mss 65495,sackOK,TS val 63498405 ecr 0,nop,wscale 7], length 0
10:14:28.406359 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40558: Flags [R.], seq 0, ack 688771957, win 0, length 0
10:14:28.591664 lo    In  IP 127.0.0.1.40568 > 127.0.0.1.40500: Flags [S], seq 325944154, win 65495, options [mss 65495,sackOK,TS val 63498590 ecr 0,nop,wscale 7], length 0
10:14:28.591670 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40568: Flags [R.], seq 0, ack 1029202136, win 0, length 0
10:14:28.699875 lo    In  IP 127.0.0.1.40570 > 127.0.0.1.40500: Flags [S], seq 230932052, win 65495, options [mss 65495,sackOK,TS val 63498698 ecr 0,nop,wscale 7], length 0
10:14:28.699880 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40570: Flags [R.], seq 0, ack 1238378028, win 0, length 0
10:14:28.883186 lo    In  IP 127.0.0.1.40582 > 127.0.0.1.40500: Flags [S], seq 1648067009, win 65495, options [mss 65495,sackOK,TS val 63498882 ecr 0,nop,wscale 7], length 0
10:14:28.883191 lo    In  IP 127.0.0.1.40500 > 127.0.0.1.40582: Flags [R.], seq 0, ack 1648067010, win 0, length 0
10:14:28.988414 lo    In  IP 127.0.0.1.40586 > 127.0.0.1.40500: Flags [S], seq 1410782548, win 65495, options [mss 65495,sackOK,TS val 63498987 ecr 0,nop,wscale 7], length 0

```
