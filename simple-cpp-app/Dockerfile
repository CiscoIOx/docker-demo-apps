FROM devhub-docker.cisco.com/iox-docker/base-x86_64

COPY apps /opt/apps/
RUN opkg update
RUN opkg install libstdc++
CMD ["/opt/apps/sample_app"]
