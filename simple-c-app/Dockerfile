FROM devhub-docker.cisco.com/iox-docker/ir800/base-rootfs

COPY apps /opt/apps/
RUN opkg update
CMD ["/opt/apps/loop_app"]
