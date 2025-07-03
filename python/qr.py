import os
import qrcode

img = qrcode.make("https://youtube/xyFZjo5PgG0")

img.save("qr.png", "PNG")
