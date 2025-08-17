The Smart-Nametag program is designed to support the well-being of the elderly by continuously monitoring their vital signs, activities, and location through a wearable device. The nametag integrates several key sensors, such as:
- Heart rate sensor (MAX30123)
- Temperature sensor (MLX90614)
- Motion sensor (GY-85)
- Infrared sensor (AS312)
- Blood pressure sensor
- GPS sensor

These sensors collect real-time health and activity data, which is processed by a microcontroller (ESP32) and then transmitted to a cloud-based platform using IoT connectivity.

💻 The Website/Dashboard plays the most crucial role in this system. It functions as the main interface for caregivers, doctors, or family members to:
- Monitor Health Data in Real-Time
The dashboard displays vital signs such as heart rate, body temperature, and blood pressure, ensuring that any abnormal conditions can be detected quickly.
- Track Location and Activities
Using GPS and motion sensors, caregivers can see the elderly’s movement and position on an interactive map, which is especially useful for preventing accidents or locating someone in case of emergencies.
- Manage Alerts and Notifications
The system highlights critical warnings (e.g., abnormal heart rate, sudden falls, or irregular blood pressure), allowing immediate action.
- Data Visualization and History
The dashboard provides clear visual analytics with charts, color-coded indicators, and daily activity summaries, enabling caregivers to track trends and make informed healthcare decisions.

In short, while the wearable Smart-Nametag is the data collector, the website is the central hub that transforms raw sensor data into actionable insights. This makes it easier for caregivers to deliver proactive and personalized care for the elderly, improving safety, health management, and overall quality of life.

## System Overview
<img src="images/1.png" alt="Smart-Nametag overview" width="900" />
<img src="images/2.png" alt="Dashboard UI" width="900" />

## Web Dashboard (Main Feature)
- Real-time vitals: heart rate, temperature, blood pressure
- Activity & location tracking (map)
- Alerts & notifications for abnormal events
- Trends and history with clear visualizations



## Tech Stack
- **Hardware:** ESP32 + MAX30123, MLX90614, GY-85, AS312, BP sensor, GPS
- **Connectivity:** Wi-Fi / IoT to cloud
- **Frontend:** Web dashboard for monitoring
