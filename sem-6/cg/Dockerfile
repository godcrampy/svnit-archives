# Set ubuntu as base image
FROM ubuntu:xenial

# Install dependencies
RUN apt-get update && \
  apt-get -y install sudo

RUN sudo apt-get -y install build-essential

RUN apt-get -y install wget

RUN sudo apt-get -y install libsdl-image1.2 libsdl-image1.2-dev \
  libsdl1.2debian libart-2.0-dev libaudiofile-dev \
  libdirectfb-dev libdirectfb-extra libfreetype6-dev \
  libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev \
  libslang2-dev libasound2 libasound2-dev

RUN apt-get -y install xauth

EXPOSE 8887

COPY . .

WORKDIR "/libgraph-1.0.2"

# RUN ./configure --disable-guile

# RUN make

# RUN sudo make install

# RUN sudo cp /usr/local/lib/libgraph.* /usr/lib

# RUN gcc -o sample sample.c -lgraph

RUN xauth add localhost.localdomain/unix:0  MIT-MAGIC-COOKIE-1  677097efeb2a43b35926dc8457a8b29b
