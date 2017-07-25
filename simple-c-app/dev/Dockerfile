FROM devhub-docker.cisco.com/iox-docker/ir800/base-rootfs

COPY src /opt/src/
RUN opkg update
RUN opkg install iox-toolchain
RUN opkg install gdb
