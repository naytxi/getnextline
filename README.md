![github-header-image(4)](https://github.com/user-attachments/assets/9e689ece-a7f7-4a16-83af-e8092b0e12a5)
![gif](https://i.pinimg.com/564x/d1/93/60/d19360467328a097a7d276646b67676d.jpg)

🖐️ Hi! 
I'm Nay 
I'm currently learning to code.

<h2>🚀ABOUT</h2>

The aim of this project is to make you code a function that returns a line, read from a file descriptor.
Get_next_line is a simple and challenging project which allows you to learn deeply about open(), read() and close() functions as well as static variables and file descriptors.

<h2>❓HOW IT WORKS</h2>

Let's walk through a typical lifecycle of our static buffer:

  **First Call:**
  
        We allocate memory for buffer and read from the file.
        We extract the first line and return it.
        Any leftover data stays in buffer.

  **Subsequent Calls:**
  
        buffer still contains the leftover data from last time.
        We start by checking if there's a complete line in buffer.
        If not, we read more from the file and append to buffer.
        We extract the next line and update buffer again.

  **Last Call:**
  
        We've reached the end of the file.
        We return any remaining data in buffer.
        We free buffer and set it to NULL.

<h2>🔍UTILITY</h2>

**Efficiency:** We don't need to re-read the entire file for each line. We just continue from where we left off.

**Simplicity:** The static variable handles the state management for us. No need to pass around a pointer to keep track of our position.

**Memory Management:** We can allocate memory once and reuse it, rather than allocating new memory for each function call.

<h2>👀EXAMPLE</h2>

Imagine you're reading this article It would go something like this:

  First call: "Hi!"
  
  Second call: "I'm Nay"
  
  Third call: "I'm currently learning to code!"

...and so on, until it reaches the end of the file.
