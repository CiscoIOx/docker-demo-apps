FROM dockerhub.cisco.com/iox-docker-dev/base_ir800_devhub

COPY src /opt/src/
RUN opkg update
RUN opkg install iox-toolchain
RUN opkg install gdb
