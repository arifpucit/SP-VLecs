#!/bin/bash
while true
do
  rm -f /tmp/time_fifo
  mkfifo /tmp/time_fifo
  sleep 1
  date 1> /tmp/time_fifo
done
