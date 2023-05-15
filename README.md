# algoritmaanalizivetasarimidersi2.kisasinav1.kisim
KOD NE İŞE YARAR VE NASIL ÇALIŞIR?

Bu C dilinde yazılmış bir kod örneğidir ve aşağıdaki işlemleri gerçekleştirir:

1.	A_SIZE boyutunda (20) bir tamsayı dizisi oluşturur ve bu diziyi rastgele sayılarla doldurur. Bu sayılar -MAX_W ile MAX_W arasındadır.

2.	Bu diziyi artan sırayla sıralar (Bubble sort kullanarak).

3.	Sıralanmış dizide, ardışık elemanların toplamının pozitif olduğu en uzun alt dizi bulunur ve bu alt dizinin elemanlarının toplamı t olarak atanır. Daha sonra t değeri, ardışık pozitif sayıların sayısına bölünerek t güncellenir.

4.	G_SIZE x G_SIZE (10 x 10) boyutunda bir g matrisi oluşturur ve bu matrisi önceden tanımlanmış değerlerle doldurur.

5.	Bu g matrisi üzerinde Floyd-Warshall algoritması kullanarak tüm çiftlerin en kısa yolunu bulur ve sonuçları d adında başka bir matrise kaydeder.

6.	İki düğüm arasındaki en kısa yolun uzunluğu, daha önce hesaplanan t değerinden küçük olan tüm yolları yazdırır.

7.	Kodun çalışma süresini hesaplar ve ekrana yazdırır.

Kodun çalışması şu şekildedir:

•	main fonksiyonu içinde, dizi ve matrisler oluşturulur ve rastgele sayılarla doldurulur.

•	Daha sonra sırasıyla function1, function2 ve function3 fonksiyonları çağrılır ve işlemler gerçekleştirilir.

•	İlgili fonksiyonlar tarafından gerçekleştirilen işlemlerin sonuçları ekrana yazdırılır. Bu işlem sırasında, print1, print2 ve print3 fonksiyonları kullanılır.

•	Kodun çalışma süresi hesaplanır ve ekrana yazdırılır.


KODUN ZAMAN KARMAŞIKLIĞI

1.	generate() fonksiyonu: O(n) zaman karmaşıklığına sahiptir, çünkü boyutu n olan diziyi baştan sona doldurur.

2.	function1() fonksiyonu: Bu fonksiyon, Bubble Sort algoritması kullanarak dizi sıralama işlemi yapar. O(n^2) zaman karmaşıklığına sahiptir, çünkü iki iç içe döngü kullanılır ve her döngü n elemana kadar çalışır.

3.	function2() fonksiyonu: Bu fonksiyon, boyutu n olan diziyi baştan sona tarar ve karmaşıklığı O(n)'dir.

4.	function3() fonksiyonu: Floyd-Warshall algoritması kullanarak graflarda en kısa yolları hesaplar. Bu fonksiyon, üç iç içe döngü kullanır ve her döngü G_SIZE (n) elemana kadar çalışır. Bu nedenle zaman karmaşıklığı O(n^3)'tür.

5.	print1() fonksiyonu: Bu fonksiyon, boyutu n olan diziyi baştan sona yazdırır ve O(n) zaman karmaşıklığına sahiptir.

6.	print2() ve print3() fonksiyonları: Her iki fonksiyon da matrisi baştan sona yazdırır ve iki iç içe döngü kullanır. Bu nedenle, her iki fonksiyonun da zaman karmaşıklığı O(n^2)'dir.

Ana fonksiyon (main()) içinde bu fonksiyonların çoğu çağrılır ve ardışık olarak çalışır. Dolayısıyla, toplam zaman karmaşıklığı, bu fonksiyonların zaman karmaşıklıklarının toplamına eşittir:

O(n) + O(n^2) + O(n) + O(n^3) + O(n) + O(n^2) + O(n^2) = O(n^3)

Ana fonksiyonun zaman karmaşıklığı, en yüksek dereceli polinom olan O(n^3)'tür.


KODU NASIL GELİŞTİREBİLİRİZ?

1.	Kodun okunabilirliğini ve anlaşılabilirliğini artırmak için fonksiyon ve değişken isimlerini daha açıklayıcı hale getirebiliriz.

2.	Kodu daha modüler hale getirebiliriz. Fonksiyonlar arasında ortak kullanılan işlemleri yeni bir fonksiyon olarak tanımlayabiliriz.

3.	Hata kontrolü ve girdi doğrulama ekleyebiliriz. Fonksiyonlara yanlış parametrelerin geçirilmesi durumunda uygulamanın düzgün çalışmamasını önlemek için hata kontrolü ve girdi doğrulama ekleyebiliriz.

4.	Global değişkenler yerine yerel değişkenler kullanabiliriz. Özellikle ‘A_SIZE’, ‘G_SIZE’ VE ‘MAX_W’ gibi sabit değerler yerine, bunları programın parametreleri olarak tanımlayarak daha esnek hale getirebiliriz.

5.	Açıklama ve yorum ekleyebiliriz. 

6.	Fonksiyonlar arasında veri paylaşımını geliştirebiliriz. 

7.	Performans optimizasyonları uygulayabiliriz. 


GELİŞTİRDİĞİMİZ KODUN ZAMAN KARMAŞIKLIĞI

1.	generateRandomArray fonksiyonu: Bu fonksiyon, boyutu ARRAY_SIZE olan bir dizi oluşturur ve her elemana rastgele bir değer atar. Bu işlem, dizideki her eleman için gerçekleştirildiğinden, zaman karmaşıklığı O(n)'dir.

2.	bubbleSort fonksiyonu: Bu fonksiyon, Bubble Sort algoritmasını kullanarak bir diziyi sıralar. Bu algoritma, kötü durumda O(n^2) zaman karmaşıklığına sahiptir.

3.	findAverageMaximumSubarraySum fonksiyonu: Bu fonksiyon, dizideki maksimum alt dizi toplamını bulmak için boyutu ARRAY_SIZE olan bir dizi üzerinde çalışır. Bu işlem, dizideki her elemanı bir kez kontrol ettiği için, zaman karmaşıklığı O(n)'dir.

4.	floydWarshallAlgorithm fonksiyonu: Bu fonksiyon, Floyd-Warshall algoritmasını kullanarak bir grafın tüm çiftler arasındaki en kısa yollarını hesaplar. Bu algoritma, her düğüm için her başka düğüm çiftini kontrol ettiği için O(n^3) zaman karmaşıklığına sahiptir (n = GRAPH_SIZE).

Sonuç olarak, bu kodun toplam zaman karmaşıklığı, ana bölümde gerçekleştirilen işlemlerin zaman karmaşıklıklarının toplamıdır:

O(n) + O(n^2) + O(n) + O(n^3)

Burada n, ARRAY_SIZE ve GRAPH_SIZE'nin en büyüğü olarak kabul edilebilir. Kodun zaman karmaşıklığı, en büyük terim olan O(n^3) ile sınırlıdır.


HER İKİ KODUN ZAMAN KARMAŞIKLIKLARI VE ÇALIŞMA SÜRELERİNİN KARŞILAŞTIRILMASI

Her iki kod da aynı problemleri çözmektedir ve yapıları çok benzerdir. İkisinin zaman karmaşıklığı ve çalışma süresi için karşılaştırma yapalım:

1.	generateRandomArray (Dizi Oluşturma) ve function1 (Bubble Sort) işlemlerinin karmaşıklığı O(n^2)'dir, çünkü Bubble Sort algoritması kullanılıyor.

2.	function2 (Ortalama Maksimum Alt Dizi Toplamı Bulma) işleminin karmaşıklığı O(n)'dir, çünkü diziyi tek seferde gezmektedir.

3.	function3 (Floyd-Warshall Algoritması) ve floydWarshallAlgorithm işlemlerinin karmaşıklığı O(n^3)'dür, çünkü grafikte tüm düğümler arasındaki en kısa yolları hesaplamak için Floyd-Warshall algoritması kullanılıyor.

Her iki kodda da işlemler aynı olduğu için, toplam zaman karmaşıklığı ve çalışma süreleri de benzer olacaktır. Yani, her iki kodun zaman karmaşıklığı O(n^3 + n^2 + n) ve çalışma süreleri arasında önemli bir fark olmamalıdır.

Fakat, gerçek çalışma süreleri işlemci, bellek ve diğer sistem kaynaklarından etkilenebilir. Bu nedenle, iki kodun çalışma sürelerini karşılaştırmak için aynı sistemde ve benzer koşullar altında çalıştırılmalıdırlar.

