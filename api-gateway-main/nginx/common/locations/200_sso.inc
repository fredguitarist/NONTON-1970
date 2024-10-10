location /sso {
    proxy_read_timeout 60s;
    client_max_body_size 16m;

    proxy_pass http://u_sso;
    include include/proxy.headers;
    proxy_http_version 1.1;
    proxy_set_header   Upgrade $http_upgrade;
    proxy_set_header   Connection keep-alive;
    proxy_set_header   Host $host;
    proxy_set_header   Accept-Encoding *;
    proxy_cache_bypass $http_upgrade;
    proxy_set_header   X-Forwarded-For $proxy_add_x_forwarded_for;
    proxy_set_header   X-Forwarded-Proto $scheme;
    proxy_set_header X-Real-IP $remote_addr;
    proxy_buffer_size 256k;
    proxy_buffers 4 512k;
    proxy_busy_buffers_size 512k;
    proxy_hide_header X-Content-Type-Options;
}
