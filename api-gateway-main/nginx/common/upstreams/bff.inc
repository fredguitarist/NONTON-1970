upstream u_website_bff {
    server website_bff:80 max_fails=0;
    keepalive 32;
}
