FROM devhub-docker.cisco.com/iox-docker/ir800/base-rootfs

RUN opkg update && opkg install python
COPY poll-temperature.py /usr/bin/poll-temperature.py
RUN chmod 777 /usr/bin/poll-temperature.py

CMD /usr/bin/poll-temperature.py
