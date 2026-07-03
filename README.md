
### 📱 HexaGlam_K Mobile Application Development

The HexaGlam_K mobile application was developed using MIT App Inventor to provide an intuitive interface for controlling and monitoring the ESP32-based Hexapod Robot. The application consists of multiple screens, each designed for a specific functionality, making robot operation simple and user-friendly.

### Step 1: Designing the Home Screen

The development began by creating the Home Screen, which serves as the application's landing page. A clean and attractive user interface was designed with the project title, robot image/logo, and navigation buttons. This screen allows users to easily access different modules of the application such as Robot Control, Sensor Dashboard, Camera Monitoring, and About sections. Proper alignment, icons, and color themes were chosen to enhance the overall user experience.

Features

Project title and logo
User-friendly interface
Navigation buttons for all modules
Clean and responsive layout

### Step 2: Developing the Robot Control Screen

A dedicated Control Screen was developed to operate the Hexapod robot remotely. Large control buttons were added to send Bluetooth commands to the ESP32. Each button transmits a predefined command that controls the robot's movements.

The implemented control functions include:
<ul>
  <li>Stand</li>
   <li>Walk</li>
   <li>Dance</li>
   <li>Halt</li>

</ul>

### Step 3: Creating the Sensor Dashboard

A Sensor Dashboard was developed to display real-time environmental data collected by the sensors connected to the ESP32. The dashboard retrieves data from the ThingSpeak cloud platform and presents all sensor readings on a single screen.

The integrated sensors include:
<ul>
  <li>🌡 Temperature Sensor</li>
   <li>🌧 Rain Sensor</li>
   <li>🌱 Soil Moisture Sensor</li>
   <li>🔥 Flame Sensor</li>
   <li>🔊 Sound Sensor</li>
   <li>📡 IR Obstacle Sensor</li>
</ul>

Each sensor value is displayed inside individual cards with appropriate labels, making the dashboard easy to understand and monitor.
<table>
  <tr>
    <td >
       <img src="https://github.com/Malavegeetanjali0481/HexaGLAM_K/blob/main/App/home%20screen%20new.jpeg" width = "22%" height="20%" alt="Home Screen">
   <img src="https://github.com/Malavegeetanjali0481/HexaGLAM_K/blob/main/App/control_screen_new.jpeg" width = "22%" height="8%" alt="">
    <img src="https://github.com/Malavegeetanjali0481/HexaGLAM_K/blob/main/App/sensor_Db.jpeg" width = "22%" height="20%" alt="">
     <img src="https://github.com/Malavegeetanjali0481/HexaGLAM_K/blob/main/App/sensors%20graph.jpeg" width = "22%" height="32%" alt="">
    </td>
  </tr>
</table>
 





