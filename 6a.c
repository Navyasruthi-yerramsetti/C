mkdir docker-web
cd docker-web

echo "<h1>Hello Docker</h1>" > index.html

docker run -d -p 8080:80 -v ~/docker-web:/usr/local/apache2/htdocs/ httpd
