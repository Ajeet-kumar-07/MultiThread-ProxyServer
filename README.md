
# 🚀 Multithreaded Proxy Server with Caching (C++)

![Language](https://img.shields.io/badge/C%2B%2B-17-blue)
![Threads](https://img.shields.io/badge/MultiThreaded-Yes-green)
![Platform](https://img.shields.io/badge/Platform-Linux%20%2F%20WSL-orange)
![Status](https://img.shields.io/badge/Project-Active-brightgreen)
![License](https://img.shields.io/badge/License-MIT-purple)

A high-performance **multithreaded proxy server** written in C++, capable of handling multiple client connections in parallel and caching HTTP responses for faster repeated access.

---

## 📸 Screenshots

> 📂 Place your images inside the `screenshots/` folder and update filenames if needed.

### 🧵 Terminal Output (on client request)
![Terminal Output](screenshots/terminal-log.png)

### 🌐 Postman Proxy Setup
![Postman Setup](screenshots/postman-proxy.png)

---

## 📌 Features

- 🌐 Acts as a forward proxy for HTTP traffic
- 🧵 Handles multiple clients using `std::thread`
- 🧠 In-memory caching with thread-safe access
- ⚡ Fast response delivery from cache
- 📄 Simple request logging (can be extended)

---

## 📁 Project Structure

```
📦ProxyServer
 ┣ 📄 main.cpp             # Entry point
 ┣ 📄 proxy_server.hpp     # ProxyServer class header
 ┣ 📄 proxy_server.cpp     # Core logic for sockets and threading
 ┣ 📄 cache.hpp            # Thread-safe caching logic
 ┣ 📁 screenshots/         # Screenshots for README
 ┗ 📄 README.md            # This file
```

---

## 🛠️ Requirements

- ✅ C++17 or later
- ✅ Linux environment (native or WSL)
- ✅ g++ compiler

---

## ⚙️ Compilation & Running

### 🔧 Compile:

```bash
g++ main.cpp proxy_server.cpp -o proxy -pthread
```

### ▶️ Run:

```bash
./proxy
```

> The server will listen on port **8080** by default. You can change it in `main.cpp`.

---

## 🔍 How to Test

### ✅ Test with `curl`:

```bash
curl -x http://localhost:8080 http://ajeet.com
```

### ✅ Test with Postman:

1. Open **Postman**
2. Go to ⚙️ Settings → **Proxy**
3. Enable **Custom proxy configuration**
4. Set:
   - Proxy Host: `localhost`
   - Proxy Port: `8080`
5. Send a GET request to:
   ```
   http://ajeet.com
   ```

---

## 📦 Caching Behavior

- ✅ First time: fetches response (dummy or real)
- 🧠 Then stores it in an in-memory cache
- 🔁 Next time: serves instantly from cache

---

## 🧱 Technologies Used

- `C++17`
- `std::thread` for concurrency
- `std::mutex` for thread-safe caching
- POSIX sockets (`<sys/socket.h>`, `<netinet/in.h>`)
- Developed using WSL (Ubuntu on Windows)

---

## 🚧 Future Improvements

- [ ] Real HTTP request forwarding to target servers
- [ ] HTTPS support via `CONNECT` tunneling
- [ ] LRU cache with size limits
- [ ] Thread pool instead of unbounded threads
- [ ] Logging to file
- [ ] Blocking/filtering of domains

---

## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue to discuss the design or scope before submitting.

---

## 🧑‍💻 Author

**Ajeet Kumar**  
🔗 GitHub: [@Ajeet-kumar-07](https://github.com/Ajeet-kumar-07)

---

