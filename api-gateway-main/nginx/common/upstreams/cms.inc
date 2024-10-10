upstream u_cms {
    server bitrix:80  max_fails=0;
    keepalive 32;
}
