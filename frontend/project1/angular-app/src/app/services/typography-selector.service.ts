import { Injectable, signal } from '@angular/core';
import { MatDialog } from '@angular/material/dialog';
import { TypographySelectorComponent } from '../dialogs/typography-selector.component';
import { Observable } from 'rxjs';
import { tap } from 'rxjs/operators';

@Injectable({
  providedIn: 'root'
})
export class TypographySelectorService {
  readonly fontFamily = signal<string>('"Roboto", "Helvetica", "Arial", sans-serif');

  constructor(private readonly dialog: MatDialog) { }

  openTypographySelector(): Observable<{ fontFamily: string } | undefined> {
    return this.dialog.open(TypographySelectorComponent, {
      width: '400px',
      height: '300px',
      disableClose: false
    }).afterClosed().pipe(
      tap(result => {
        if (result) {
          this.fontFamily.set(result.fontFamily);
        }
      })
    );
  }
}