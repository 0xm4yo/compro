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
    git \
    openssh-client && \
    rm -rf /var/lib/apt/lists/*

# # Add GitHub to known hosts
RUN mkdir -p /root/.ssh && \
    touch /root/.ssh/known_hosts && \
    ssh-keyscan github.com >> /root/.ssh/known_hosts

RUN git config --global core.autocrlf true

# Set up a working directory
WORKDIR /workspace