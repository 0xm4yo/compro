# Use Ubuntu as base image
FROM ubuntu:latest

# Set timezone to Japan Standard Time (JST)
ENV TZ=Asia/Tokyo

# Install packages
RUN apt-get update && \
    apt-get install -y \
    build-essential \
    gcc \
    g++ \
    gdb \
    python3 \
    python3-pip \
    python3-dev \
    clangd \
    git \
    openssh-client && \
    rm -rf /var/lib/apt/lists/*

RUN git config --global core.autocrlf true