import { Component, signal } from '@angular/core';
import { MaterialDemoComponent } from './material-demo.component';

@Component({
  selector: 'app-root',
  imports: [MaterialDemoComponent],
  templateUrl: './app.html',
  styleUrl: './app.scss'
})
export class App {
  protected readonly title = signal('angular-app');
}
