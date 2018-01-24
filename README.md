# CarND Term 2 PID Controller
Self-Driving Car Engineer Nanodegree Program Term 2

---

## PID Algorithm

The base algorithm is implemented in the GetControlValue method of the PID.cpp file.  As per the lessons, we use constants for each of the proportional, differential and integral parts of the model (Kp, Kd and Ki respectively).

#### Manual Tuning

I tuned the PID model manually, and then tried to optimize automatically after reaching a point in which the model could complete an entire circuit of the track.  Since the sim didn't easily allow for a restart or reset, the Twiddle method was not easily implemented, and I opted for a more brute-force method.  (I did see that it the sim accepted a 'reset' command, but this merely severed messages between the server and client and did not put the vehicle back at the beginning of the track.)

I used a static var to keep track of the number of telemetry messages sent between server and client and used this value for time steps.  Three thousand (3000) time steps equate to about one full lap around the track.

I attempted to tune Kp, the proportional value first.  It seemed a wide range of values almost worked for Kp, but in most cases, strong oscillations started from which the vehicle could not recover.

Tuning Kd, the differential constant was the solution to this.  A correct value of Kd would damp oscillations and allow the vehicle to recover, and to make quick changes in times where a sharp curve occurred.  Kd was much higher than Kp, which makes sense.  Large differences in cte in one time step need to be compensated for quickly, and a larger value does this.  Too small a value for Kd did not allow for quick enough responses, while too large made for a very jerky movement, with the steering acting too quickly and slowing speed.

Tuning Ki had very little effect in this instance.  If there was a steering bias or some other bias, then it would probably be beneficial for those cases.  In this case, small changes had very little effect, though large values could make the model unstable.

#### 'Automatic' Tuning

After I reached a point in which I could successfully navigate around the entire track, I attempted to implement a sort of automatic tuning.  This consisted of a simple call to OptimizeParams after 3000 time steps (chosen arbitrarily), calculating the error and writing that and the K values out to a file.  I would then increment the value by some amount (usually about 10% of the original choice), and run a second lap.  After several laps, I could check the file for the smallest error.  In this way, I could tune to slightly better values, though not very efficiently.

I finally ended up with values of Kp = 4.3, Kd = 55, and Ki = 0.004.
