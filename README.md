# 🚀 Multithreaded Proxy Server with Caching (C++)

A high-performance multithreaded proxy server written in C++, capable of handling multiple client connections in parallel and caching HTTP responses for faster subsequent access.

## 📌 Features

- 🌐 Acts as a forward proxy for HTTP traffic
- 🧵 Handles multiple clients using `std::thread`
- 🧠 In-memory caching with thread-safe access
- ⚡ Fast response delivery from cache
- 📄 Simple request logging (can be extended)

---


---

## 🛠️ Requirements

- ✅ C++17 or later
- ✅ Linux environment (e.g., WSL or native)
- ✅ g++ compiler

---

## ⚙️ Compilation & Running

### 🔧 Compile:

```bash
g++ main.cpp proxy_server.cpp -o proxy -pthread
```

### Run 
```bash
./proxy
```

---

## 📦 Caching Behavior
# When a URL is requested:

  🔁 If it's cached: Response is served from memory
  🌐 If not cached: A dummy response (or real fetch if implemented) is returned and stored

# this can be extend this with:

  LRU cache

  File-based caching
---

## 🧱 Technologies Used
C++17

std::thread (multithreading)

std::mutex (thread safety)

POSIX sockets (<sys/socket.h>, <netinet/in.h>)

WSL/Ubuntu for development on Windows

## 🤝 Contributing
  Pull requests are welcome. For major changes, please open an issue first to discuss what you'd like to change.

