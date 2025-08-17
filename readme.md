## Использование

### Расчёт среднеарифметического
cat ./inpit/AB_NYC_2019.csv | mapper | reducer    
или    
cat ./inpit/AB_NYC_2019.csv | mapper | reducer /avg

### Расчёт дисперсии
cat ./inpit/AB_NYC_2019.csv | mapper | reducer /dsp
