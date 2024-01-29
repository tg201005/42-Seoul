set -e

mkdir -p /etc/nginx/ssl

openssl req -x509 -nodes -days 365 \
        -keyout /etc/nginx/ssl/tyi.42.fr.key \
        -out /etc/nginx/ssl/tyi.42.fr.crt \
        -subj "/C=KR/L=Seoul/O=42Seoul/CN=tyi.42.fr" \
        -newkey rsa:2048 \

exec nginx -g "daemon off;"