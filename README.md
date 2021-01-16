# Drone projesi kanal sinyallerinin kablosuz transferi ve PPM sinyalinin üretilmesi
# Verici (Transmitter) işlevi gören NRF24L01 + PA ve Arduino (Arduino 1)
<p> İlk önce 1. Arduino'muz olan transmitter (yani verici) Arduino'muza transmitter.ino kodunu yükleyelim. 
Unutmayın Arduino'nun {A0, A1, A2, A3} analog giriş pinlerini joysticklerin çıkış bacaklarına bağlamalısınız. 
NRF24L01+PA modülünü adaptörüne takın ve adaptörün CE çıkışını Arduino'nun Digital 7 (D7), CSN çıkışını Arduino'nun D8, SCK çıkışını Arduino'nun D13, MO çıkışını D11 ve de MI çıkışını Arduino'nun D12 girişine bağlayın. 
Ayrıca NRF24L01 adaptörünün üzerindeki Vcc çıkışını Arduino'nun 5V, GND çıkışını Arduino'nun GND pinine bağlayın. 
NRF24L01 ADAPTÖRÜNÜN Vcc ÇIKIŞINI 3.3V'a bağlamayın. Zaten adaptör 5V'dan 3.3V'a voltajı regüle ediyor ve ayrıca stabil (yani kararlı ve güvenilir) bir voltaj sağlıyor. 
Eğer NRF24L01 adaptörünüz yoksa bağlantıları yine bahsedilen konfigürasyonda yapabilirsiniz ama Vcc ile GND arasına 10uF'lık elektrolitik kapasitör bağlamanız tavsiye ediliyor. 
Sadece NRF24L01 kullanıyorsanız (adaptörünüz yoksa) SAKIN Vcc'ye 5V bağlamayın, NRF24L01'e zarar verirsiniz.
  
NRF24L01 kablosuz modül<br/>
https://www.direnc.net/nrf24l01-wireless-modul<br/>
NRF24L01kablosuz modül adaptörü<br/>
https://www.direnc.net/8-pin-nrf24l01-wireless-modul-adaptoru<br/>
NRF24L01 + PA kablosuz modülü (daha kuvvetli bir iletişim - anten var)<br/>
https://www.direnc.net/nrf24l01-plus-pa-wireless-modul

# Alıcı (Receiver) işlevi gören NRF24L01 + Arduino (Arduino 2)
Yukarıda anlatılan verici (transmitter) kodunu yükledikten sonra 2. Arduino'ya receiver.ino kodunu yükleyin ve Arduino IDE ayarlar --> port --> COMX<br/>
Burada X 2. Arduino'nun COM numarası, sakın transmitter olan 1. Arduino'nun COM adresini seçmeyin. Doğru COM numarasını seçtikten sonra sağ üstte seri port penceresini açıp sağ altta seri port iletişim hızı olan baud rate'i 57600 seçin ve JOYSTICK ile oynayarak ekranda kanal 1 ve 2 değerlerinin değiştiğini gözlemleyin. Eğer yukarı-aşağı hareketi yapan potansiyometrenin çıkışını verici konumunda olan 1. Arduino'nun A0 pinine bağladıysanız, JOYSTICK ile yukarı-aşağı hareketini yaptığınızda ekranda 1. kanal sinyalinin [0-255] arasında değiştiğini göreceksiniz. Benzer mantıkla, eğer sağa-sola hareket yapan potansiyometrenin çıkışını verici konumunda olan 1. Arduino'nun A1 pinine bağladıysanız, JOYSTICK ile sağ-sol hareketini yaptığınızda ekranda 2. kanal sinyalinin [0-255] arasında değiştiğini göreceksiniz.<br/> 
# Arduino --> MATLAB Seri Port iletişimi ile kanal sinyallerinin görselleştirilmesi
Ardından MATLAB kodumuz olan serial_port_receiver.m dosyasını doğru port ismini girerek çalıştırın. Doğru portu belirlemek için MATLAB'ı açınca serialportlist komutunu kullanabilirsiniz veya Windows'da Aygıt Yöneticisi'ne gidip orada Bağlantı Noktaları (COM ve LPT) üzerine tıklayabilirsiniz. 
Yukarıda Code yazan yeşil bağlantıya tıklarsanız bu sayfadaki kodları zip dosyası halinde bilgisayarınıza indirebilirsiniz. </p> </br></br>
![](connections.jpg) </br></br>
# Videoyu aşağıdaki resime tıklayarak izleyebilirsiniz 
[![IMAGE ALT TEXT HERE](https://i9.ytimg.com/vi/qr29ZdE75gk/mq2.jpg?sqp=CPiL0v8F&rs=AOn4CLBpe-X4oI4UrLHCcvzVKjUKVWQrVg)](https://www.youtube.com/watch?v=qr29ZdE75gk)</br></br>
