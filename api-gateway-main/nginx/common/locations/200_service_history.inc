location /service/history/ {
    auth_basic $auth;
    auth_basic_user_file /etc/nginx/.htpasswd;
    proxy_read_timeout 60s;
    client_max_body_size 16m;

    proxy_pass http://u_ms_history/;
    include include/proxy.headers;
}
