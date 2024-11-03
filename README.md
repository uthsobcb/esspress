# Esspress

### A Web Server Built with C!

Hello! This project is an experimental build for my Software Development course this semester, where I'm required to use C programming and a `.txt` file as the database.

![Project Meme](/assets/image.png)

Since I couldn't use a modern database, I decided to create a basic one using a `.txt` file. Along the way, I wondered: could I build a web server in C that relies solely on a single text file for data storage? And here we are—Esspress was born, developed with socket programming and designed to handle basic HTTP requests.

### Documentation

This project is a minimal web server that listens on a specified port and supports simple `/GET` requests.

#### How to Run Locally

1. Clone the repository:
   ```bash
   git clone git@github.com:uthsobcb/esspress.git
   ```

2. Change into the project directory:
   ```bash
   cd esspress
   ```

3. Compile the server code:
   ```bash
   gcc http_server.c -o http_server
   ```

4. Run the server:
   ```bash
   ./http_server
   ```

5. Open your browser and navigate to [localhost:8001](http://localhost:8001)  
   To use the `/GET` request, go to [localhost:8001/data](http://localhost:8001/data)

### Contributing

This is a fun and exploratory project! Contributions are welcome, especially if you’re interested in adding `POST`, `DELETE`, or `PUT` request support.

Thanks for checking it out!
