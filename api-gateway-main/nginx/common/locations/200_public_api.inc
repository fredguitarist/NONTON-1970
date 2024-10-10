location /public_api/ {
    proxy_read_timeout 60s;
    client_max_body_size 16m;

    proxy_pass http://u_website_bff/;
    include include/proxy.headers;
}
