FROM devhub-docker.cisco.com/iox-docker/ir800/base-rootfs 

RUN opkg update
RUN opkg install python
RUN opkg install python-modules
RUN opkg install python-misc
COPY app/python_modules/ /usr/lib/python2.7/site-packages/
COPY app/python-c-app.py /opt/app/
COPY app/loop.sh /opt/app/
CMD ["/opt/app/loop.sh"]
