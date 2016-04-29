FROM alpine:3.3

RUN apk --update add g++ make cmake && rm -rf /var/cache/apk/*
COPY . /root/src/
RUN cd /root/src && cmake -DCMAKE_BUILD_TYPE=Release . && make && cp Fibonneo /root/ && cd /root && rm -r /root/src

EXPOSE 9000

CMD ["/root/Fibonneo"]