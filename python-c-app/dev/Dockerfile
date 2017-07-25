FROM devhub-docker.cisco.com/iox-docker/ir800/base-rootfs

RUN opkg update
RUN opkg install iox-toolchain
RUN opkg install python-pip
RUN opkg install python-misc
RUN opkg install python-dev
RUN pip install psutil
