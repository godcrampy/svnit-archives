<!DOCTYPE html>
<html>

<head>
    <title>Email</title>
    <style>
        body {
            margin: 20px 12%;
            font-family: sans-serif;
        }
    </style>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/water.css@2/out/water.css">
</head>

<body>
    <h1>Mailer: </h1>
    <form action="mail.php" method="post">
        <label>From:</label>
        <input type="email" name="send" required>
        <label>Name:</label>
        <input type="text" name="name" required>
        <label>Password:</label>
        <input type="password" name="password" required>
        <label>To:</label>
        <input type="email" name="receive" required>
        <label>CC:</label>
        <input type="email" name="cc">
        <label>BCC:</label>
        <input type="email" name="bcc">
        <label>Subject:</label>
        <input type="text" name="sub" required>
        <label>Message:</label>
        <textarea name="body"></textarea>
        <input type="submit" name="submit">
    </form>
</body>

</html>