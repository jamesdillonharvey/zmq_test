#include "zmq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  void *context = zmq_init(1);
  void *socket = zmq_socket(context, ZMQ_SUB);
  zmq_connect(socket, "tcp://127.0.0.1:12345");
  zmq_setsockopt(socket, ZMQ_SUBSCRIBE, "", 0);

  char string[1000] = "";
  while(1) {
    printf("whatever\n");
    sleep(10);
  }
}
