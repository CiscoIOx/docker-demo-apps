FROM devhub-docker.cisco.com/iox-docker/ir800/base-rootfs

COPY apps /opt/apps/
RUN opkg update
RUN opkg install libstdc++
CMD ["/opt/apps/sample_app"]
