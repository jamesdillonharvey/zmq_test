

# libzmq

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Debug
make
```

# zmq_test

```
gcc -g test.cxx -o test -L/home/ec2-user/code/libzmq/build/lib -I /home/ec2-user/code/libzmq/include/ -lzmq

export LD_LIBRARY_PATH=/home/ec2-user/code/libzmq/build/lib; ./test
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
