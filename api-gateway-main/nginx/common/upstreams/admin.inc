upstream u_admin {
    server admin:80  max_fails=0;
    keepalive 32;
}
