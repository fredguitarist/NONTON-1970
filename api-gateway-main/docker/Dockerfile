FROM fabiocicerchia/nginx-lua:1.27.0-alpine

WORKDIR /etc/nginx

COPY .htpasswd .

COPY ./nginx/common ./common

COPY ./nginx/auth-stage.inc ./common/map/auth.inc

COPY ./lua ./common/lua

COPY ./nginx/conf.d/s0_default.conf ./conf.d/default.conf

COPY ./nginx/conf.d/s1_front.conf ./conf.d/s1_front.conf

COPY ./nginx/include ./include

COPY ./nginx/nginx.conf ./nginx.conf

COPY ./nginx/s1_admin.conf ./conf.d/s1_admin.conf

COPY ./nginx/s2_cms.conf ./conf.d/s2_cms.conf
