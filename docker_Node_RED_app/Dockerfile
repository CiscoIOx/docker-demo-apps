FROM node:6-alpine
RUN apk update 
RUN apk add  python 
RUN apk add --no-cache make gcc g++ python linux-headers udev
RUN mkdir -p /usr/src/node-red
RUN mkdir -p /lib64
RUN mkdir /root/node-red
COPY usersetup /bin/
RUN chmod 777 /bin/usersetup
WORKDIR /usr/src/node-red
RUN adduser -h /usr/src/node-red -D -H -u 900 node-red && chown -R node-red:node-red /usr/src/node-red
RUN mkdir -p /.node-red
RUN chown -R node-red:node-red /.node-red
USER 900:900
COPY package.json /usr/src/node-red/
RUN npm install
RUN npm install serialport --build-from-source
RUN npm install node-red-contrib-modbus --unsafe-perm --build-from-source
ENV PATH "$PATH:/usr/sbin:/usr/bin:/sbin:/bin:/usr/local/bin"
EXPOSE 1880
ENV FLOWS=flows.json
LABEL \
    cisco.info.name="node-red" \
    cisco.info.description="devon energy node-red" \
    cisco.info.version="4.0" \
    cisco.info.author-name="Cisco" \
    cisco.type="docker" \
    cisco.resources.network.0.interface-name="eth0" \
    cisco.cpuarch="x86_64" \
    cisco.resources.profile="c1.large"

#CMD ["npm", "start", "--", "--userDir", "/data"]
CMD npm start --prefix /usr/src/node-red --userDir /root/node-red
