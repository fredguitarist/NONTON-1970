upstream u_ms_history {
    server ms_history:80  max_fails=0;
    keepalive 32;
}
