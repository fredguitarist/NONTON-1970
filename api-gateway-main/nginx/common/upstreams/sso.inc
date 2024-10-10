upstream u_sso {
    server keycloak:8080  max_fails=0;
    keepalive 32;
}
