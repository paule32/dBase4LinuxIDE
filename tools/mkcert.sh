#!/bin/bash
openssl genrsa -out api.firmen-ring.info.key 2048
openssl req -new -key api.firmen-ring.info.key -out api.firmen-ring.info.csr \
   -subj "/C=DE/ST=Thueringen/L=Eisenach/O=KALLUP non-profit/CN=api.firmen-ring.info/emailAddress=kallup.jens@web.de"
openssl x509 -req -days 1 -in api.firmen-ring.info.csr \
   -signkey api.firmen-ring.info.key -out api.firmen-ring.info.crt
