<?php


if (isset($_POST['submit'])) {
    try {

        require_once('./vendor/phpmailer/phpmailer/src/PHPMailer.php');
        require_once('./vendor/phpmailer/phpmailer/src/SMTP.php');
        require_once('./vendor/phpmailer/phpmailer/src/Exception.php');
        $from = $_POST['send'];
        $name = $_POST['name'];
        $to = $_POST['receive'];
        $password = $_POST['password'];
        $cc = $_POST['cc'];
        $bcc = $_POST['bcc'];
        $sub = $_POST['sub'];
        $body = $_POST['body'];
        $mail = new PHPMailer\PHPMailer\PHPMailer();
        // $mail->SMTPDebug = SMTP::DEBUG_SERVER;
        $mail->isSMTP();
        $mail->Host = 'smtp.gmail.com';
        $mail->SMTPAuth = true;
        $mail->SMTPSecure = 'ssl';
        $mail->Port = '465';
        $mail->isHTML();
        $mail->Username = $from;
        $mail->Password = $password;
        $mail->Subject = $sub;
        $mail->Body = $body;
        $mail->setFrom($from, $name);
        $mail->AddAddress($to);
        if ($bcc != "")
            $mail->AddBCC($bcc);
        if ($cc != "")
            $mail->AddCC($cc);
        $mail->Send();
        echo "<h2>Email sent successfully!</h2>";
    } catch (Exception $e) {
        echo "Message could not be sent. Mailer Error: {$mail->ErrorInfo}";
    }
    echo "<script>alert('From: $from To: $to \\n \\nSubject: $sub \\nBody: $body');</script>";
}
