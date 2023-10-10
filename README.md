# zmq_test

```
gcc test.cxx -o test -L/home/ec2-user/code/libzmq/build/lib -I /home/ec2-user/code/libzmq/include/ -lzmq

export LD_LIBRARY_PATH=/home/ec2-user/code/libzmq/build/lib; ./test
```


```
# set to 40000 41000
sudo vim /etc/sysctl.conf
sudo sysctl -p /etc/sysctl.conf .
sysctl net.ipv4.ip_local_port_range


sudo tcpdump -i any port 40500 -n

```
