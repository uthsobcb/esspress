#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

 
int main(){

	FILE* html_data;
	html_data = fopen("index.html","r");
	
	char response_data[1024];
	fgets(response_data, 1024, html_data);
	
	char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
	strcat(http_header, response_data);
	
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(8001);
	server_address.sin_addr.s_addr = INADDR_ANY;
	
	bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	
	int client_socket;
	char request_buffer[1024];
	while(1){
	client_socket = accept(server_socket, NULL, NULL);

	recv(client_socket, request_buffer, sizeof(request_buffer) - 1, 0);
if (strncmp(request_buffer, "GET / ", 6) == 0) {
            send(client_socket, http_header, strlen(http_header), 0);
        } 
        else if (strncmp(request_buffer, "GET /data", 9) == 0) {
            FILE* db_file = fopen("assets/db.txt", "r");
            if (db_file == NULL) {
                char *not_found_response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n 404 Database not found.";
                send(client_socket, not_found_response, strlen(not_found_response), 0);
            } else {
                char data_response[2048] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\n";
                char line[256];

                while (fgets(line, sizeof(line), db_file)) {
                    strcat(data_response, line);
                }

                send(client_socket, data_response, strlen(data_response), 0);

                fclose(db_file);
            }
        } else {
            char *not_found_response = "HTTP/1.1 404 Not Found\r\nContent-Type: text/plain\r\n\r\n404 not found.";
            send(client_socket, not_found_response, strlen(not_found_response), 0);
        }

        close(client_socket);
    }

    fclose(html_data);
	return 0;
}
